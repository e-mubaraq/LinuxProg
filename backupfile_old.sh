copyFile()
{
    file = $1
    mkdir $HOME/Backup
    cp -r "$file" $HOME/Backup
}

dir_to_backup="$1"
here=`pwd`

if [ -n "$dir_to_backup" ]
then
    findflag="-newer $dir_to_backup"
else
    findflag="-newer ."
fi
command="find . $findflag"
#$command
echo ran command: $command

for file in `$command`
do
   copyFile "$file"
done
