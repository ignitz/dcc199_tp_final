echo 'Testes-----' > tests/out/output.txt

printf '\nn = 10\n' >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input10A.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input10B.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

printf '\nn = 100\n' >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input100A.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input100B.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input100C.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input100D.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

printf '\nn = 200\n' >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input200A.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input200B.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input200C.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input200D.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

printf '\nn = 1000\n' >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input1000A.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input1000B.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input1000C.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input1000D.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

printf '\nn = 2000\n' >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input2000A.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt

printf '\nn = 3000\n' >> tests/out/output.txt

START=$(date +%s.%N)
./push_relabel < tests/input3000A.txt >> tests/out/output.txt
END=$(date +%s.%N)
DIFF=$(echo "$END - $START" | bc)
echo $DIFF >> tests/out/output.txt
