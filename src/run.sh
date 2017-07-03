echo 'Testes-----' > tests/out/output.txt

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
