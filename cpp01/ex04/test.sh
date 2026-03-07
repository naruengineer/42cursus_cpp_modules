#!/bin/bash

PASS=0
FAIL=0

check() {
	local desc="$1"
	local expected="$2"
	local actual="$3"

	if [ "$actual" = "$expected" ]; then
		echo "[PASS] $desc"
		PASS=$((PASS + 1))
	else
		echo "[FAIL] $desc"
		echo "  expected: $expected"
		echo "  actual  : $actual"
		FAIL=$((FAIL + 1))
	fi
}

# テスト用ファイルの準備
echo "hello world hello" > test1.txt
echo "aaa bbb aaa" > test2.txt
printf "hel\nlo" > test3.txt
echo "abcabc" > test4.txt

echo "=== Test 1: 基本的な置換 ==="
./sed test1.txt hello GOODBYE
check "hello -> GOODBYE" "GOODBYE world GOODBYE" "$(cat test1.txt.replace)"

echo ""
echo "=== Test 2: 複数回置換 ==="
./sed test2.txt aaa ZZZ
check "aaa -> ZZZ (複数)" "ZZZ bbb ZZZ" "$(cat test2.txt.replace)"

echo ""
echo "=== Test 3: 改行をまたがない置換 ==="
./sed test3.txt hel HEL
check "改行前後の hel -> HEL" "$(printf 'HEL\nlo')" "$(cat test3.txt.replace)"

echo ""
echo "=== Test 4: s2 が空文字列（削除） ==="
./sed test4.txt abc ""
check "abc -> 空文字（削除）" "" "$(cat test4.txt.replace)"

echo ""
echo "=== Test 5: s1 が見つからない場合 ==="
echo "hello world hello" > test5.txt
./sed test5.txt NOTFOUND replaced
check "s1 なし → そのまま" "hello world hello" "$(cat test5.txt.replace)"

echo ""
echo "=== Test 6: エラー - 引数不足 ==="
output=$(./sed 2>&1)
check "引数なし → エラー" "Usage: ./sed <filename> <s1> <s2>" "$output"

echo ""
echo "=== Test 7: エラー - s1 が空 ==="
output=$(./sed test1.txt "" abc 2>&1)
check "s1 空 → エラー" "Error: s1 must not be empty" "$output"

echo ""
echo "=== Test 8: エラー - ファイルが存在しない ==="
output=$(./sed nonexist.txt a b 2>&1)
check "存在しないファイル → エラー" "Error: could not open file: nonexist.txt" "$output"

echo ""
echo "=== 結果: PASS=$PASS / FAIL=$FAIL ==="

# 一時ファイルを削除
rm -f test1.txt test2.txt test3.txt test4.txt
rm -f test1.txt.replace test2.txt.replace test3.txt.replace test4.txt.replace
