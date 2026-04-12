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

# 元ファイルと出力ファイルの中身を比較表示
show_diff() {
	local src="$1"
	local dst="${src}.replace"

	echo "  input : $(cat "$src")"
	if [ -f "$dst" ]; then
		echo "  output: $(cat "$dst")"
	fi
}

# テスト用ファイルの準備
echo "hello world" > test1.txt
echo "aaa bbb aaa" > test2.txt
printf "hel\nlo" > test3.txt
echo "abcabc" > test4.txt

echo "=== Test 1: 基本的な置換 ==="
./sed test1.txt hello GOODBYE
check "hello -> GOODBYE" "GOODBYE world" "$(cat test1.txt.replace)"
show_diff test1.txt

echo ""
echo "=== Test 2: 複数回置換 ==="
./sed test2.txt aaa ZZZ
check "aaa -> ZZZ (複数)" "ZZZ bbb ZZZ" "$(cat test2.txt.replace)"
show_diff test2.txt

echo ""
echo "=== Test 3: 改行をまたがない置換 ==="
./sed test3.txt hel HEL
check "改行前後の hel -> HEL" "$(printf 'HEL\nlo')" "$(cat test3.txt.replace)"
show_diff test3.txt

echo ""
echo "=== Test 4: s2 が空文字列（削除） ==="
./sed test4.txt abc ""
check "abc -> 空文字（削除）" "" "$(cat test4.txt.replace)"
show_diff test4.txt

echo ""
echo "=== Test 5: s1 が見つからない場合 ==="
echo "hello world hello" > test5.txt
./sed test5.txt NOTFOUND replaced
check "s1 なし → そのまま" "hello world hello" "$(cat test5.txt.replace)"
show_diff test5.txt

echo ""
echo "=== Test 6: 改行を跨ぐs1の置換 ==="
printf "hel\nlo world" > test6.txt
./sed test6.txt "$(printf 'hel\nlo')" "HELLO"
check "hel\\nlo -> HELLO" "HELLO world" "$(cat test6.txt.replace)"
show_diff test6.txt

echo ""
echo "=== Test 7: s2に改行を含む置換 ==="
echo "hello world" > test7.txt
./sed test7.txt "hello" "$(printf 'hel\nlo')"
check "hello -> hel\\nlo" "$(printf 'hel\nlo world')" "$(cat test7.txt.replace)"
show_diff test7.txt

echo ""
echo "=== Test 8: s1とs2が同じ文字列 ==="
echo "hello world" > test8.txt
./sed test8.txt "hello" "hello"
check "hello -> hello（変化なし）" "hello world" "$(cat test8.txt.replace)"
show_diff test8.txt

echo ""
echo "=== Test 9: 空ファイル ==="
printf "" > test9.txt
./sed test9.txt "hello" "world"
check "空ファイル → 空のまま" "" "$(cat test9.txt.replace)"
show_diff test9.txt

echo ""
echo "=== Test 10: s1がs2の部分文字列（無限ループしないか） ==="
echo "aaa" > test10.txt
./sed test10.txt "a" "aa"
check "a -> aa（無限ループしない）" "aaaaaa" "$(cat test10.txt.replace)"
show_diff test10.txt

echo ""
echo "=== Test 11: エラー - 引数不足 ==="
output=$(./sed 2>&1)
check "引数なし → エラー" "Usage: ./sed <filename> <s1> <s2>" "$output"

echo ""
echo "=== Test 12: エラー - s1 が空 ==="
output=$(./sed test1.txt "" abc 2>&1)
check "s1 空 → エラー" "Error: s1 must not be empty" "$output"

echo ""
echo "=== Test 13: エラー - ファイルが存在しない ==="
output=$(./sed nonexist.txt a b 2>&1)
check "存在しないファイル → エラー" "Error: could not open file: nonexist.txt" "$output"

echo ""
echo "=== 結果: PASS=$PASS / FAIL=$FAIL ==="

# 一時ファイルを削除
rm -f test.txt test.txt.replace
rm -f test{1,2,3,4,5,6,7,8,9,10}.txt
rm -f test{1,2,3,4,5,6,7,8,9,10}.txt.replace
