for file in $(find . -type f -name "prog*.c")
do
trimmedName=$(cut -d'/' -f2 <<< $file | cut -d'.' -f1)
printf "%s" $trimmedName
gcc -o $trimmedName $file 2> /dev/null
ans=5
if [ -f $trimmedName ]
then
outPut=$(./$trimmedName)
if [ $outPut = 20 ]
then
ans=10
else
ans=7
fi
fi
printf "\t%s\n" $ans
done