#/usr/bin/sh
pass="test successful"
function report(){
if [[ ! $1 -eq 0 ]];then
pass="script failed"
fi
}

if [[ ! -f phone ]]; then
    make
fi
for (( i = 0; i < 1000; i++ )); do
echo $RANDOM $RANDOM $RANDOM | ./phone | grep -q '\(([0-9]\{3\})\|[0-9]\{3\}\)[ -]\?[0-9]\{3\}[ -]\?[0-9]\{4\}' | report
done

echo "$pass"

make clean
