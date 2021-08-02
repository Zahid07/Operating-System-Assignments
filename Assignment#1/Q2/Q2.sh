# !/bin/bash
#Name =  Muhammad Zahid
#Roll No =  19i-0469
#Section =  D

echo "Please enter '1' to see file permissions."
echo "Please enter '2' to find string in search file."
echo "Please enter '3' to add contents to dummy file."
echo "Please enter '4' to check modified date of file."
echo "Please enter 'exit' to exit"
echo -n "Please enter the option from above =  ";read option;
echo ""

FILE=$PWD/log.txt
if [ -f "$FILE" ]; then
    echo " "
    else
    touch log.txt
fi

if [ $option = "exit" -o $option -eq 5 ]; then
echo "Option exit" >> log.txt
echo "Script terminated at" $(date +"%Y-%m-%d %T") >> log.txt
echo " " >> log.txt
echo " " >> log.txt
elif [ $option -eq 1 ]; then
echo "Option 0$option is selected at" $(date +"%Y-%m-%d %T")>> log.txt


echo -n "Please enter File name = ";read fname

echo "Filename:" $fname >> log.txt
permissions=$(ls -l | grep -n $fname)
permissions1=${permissions:2:10}
#ls -l | grep -n $fname
echo "Permissions of $fname:" $permissions1 >> log.txt
echo "Permissions Changed." >> log.txt

permission=$(stat -c%a $fname)
other=$(( permission%10 ))
permission=$((permission/10))
group=$(( permission%10 ))
permission=$((permission/10))
user=$permission


user=$(( 7-user ))
group=$(( 7-group ))
other=$(( 7-other ))
chmod $user$group$other $fname
# ls -l | grep -n $fname
# echo "Other are = " $other
# echo "Group are = " $group
# echo "User are = " $user
permissions=$(ls -l | grep -n $fname)
permissions1=${permissions:2:10}
echo "Updated Permissions of $fname:" $permissions1 >> log.txt
echo "" >> log.txt
echo " " >> log.txt

elif [ $option -eq 2 ]; then



echo -n "Please enter the file name in which you want to search = "
read filename
echo -n "Please enter the string you want to search = "
read searchstring

echo "Option 0$option is selected at" $(date +"%Y-%m-%d %T") >> log.txt
echo "Filename:" $filename >> log.txt
echo "Filename:" $searchstring >> log.txt

grep $searchstring $filename >> log.txt
echo "" >> log.txt
echo " " >> log.txt

elif [ $option -eq 3 ]; then
echo "Option 0$option is selected at" $(date +"%Y-%m-%d %T") >> log.txt
echo -n "Please enter the number of lines to read = ";read N

count=1
file=dummy.txt

if [ -e dummy.txt ]; then
  echo -n ""
else
  touch dummy.txt
fi

echo ""
count=1
echo -n "Odd files are : " >> log.txt
for FILE in *;do
    if [[ $FILE != $file &&$FILE != "Q2.sh" ]]
    then
    chmod 777 $FILE
       if [ $(( $count % 2 )) -eq 1 ]
       then
            echo -n "$FILE " >> log.txt
            echo `tail -$N $FILE` >> dummy.txt
       fi
       count=$(( count+1 )) 
    fi
       
done

echo " " >> log.txt
echo -n "Even files are : "  >> log.txt  
for FILE in *;do
      if [[ $FILE != $file && $FILE != "Q2.sh" ]]
    then
    chmod 777 $FILE
       if [ $(( $count % 2 )) -eq 0 ]
       then
            echo -n "$FILE " >> log.txt
            echo `head -$N $FILE` >> dummy.txt
            
       fi
       count=$(( count+1 )) 
    fi
done

echo ""
echo ""
echo " " >> log.txt
echo "Dummy.txt is created and $N of each file is coped in it." >> log.txt
echo " " >> log.txt
echo " " >> log.txt
elif [ $option -eq 4 ]; then
echo "Option 0$option is selected at" $(date +"%Y-%m-%d %T") >> log.txt

echo -n "Please enter the file  to check = ";
read file

echo "Filename:" $file >> log.txt
current=$(date +%s);
mod_date=$(stat -c %y "$file")
mod_date1=${mod_date:0:10}
echo "Current modified date:" $mod_date1 >> log.txt

mod_date=$(stat -c "%Y" $file);
    if [ $((current - mod_date)) -gt 86400 ]; then
        touch $file
        echo "File modified" >> log.txt
              
      else 
        echo "File is not older than 24 hours" >> log.txt
    fi

echo " " >> log.txt
echo " " >> log.txt



fi


#**************** PART 1 *************

# ls -l | grep -n Ammi.txt
# permission=$(stat -c%a Ammi.txt)
# other=$(( permission%10 ))
# echo "Other are = " $other
# permission=$((permission/10))
# group=$(( permission%10 ))
# echo "Group are = " $group
# permission=$((permission/10))
# user=$permission
# echo "User are = " $user


# echo ""
# user=$(( 7-user ))
# group=$(( 7-group ))
# other=$(( 7-other ))
# sudo chmod $user$group$other Ammi.txt
# ls -l | grep -n Ammi.txt
# echo "Other are = " $other
# echo "Group are = " $group
# echo "User are = " $user
# permission=$(stat -c%a Ammi.txt)
# echo $permission

####################  Q2 ##############
# start=0;
# end=0;
# find=h.
# length1=${#find}
# input="2.txt"
# space=" "
#  while IFS= read -r line
# do
#     length1=${#find}
#     length=${#line}
#     echo "$line"
#     start=0;
#     end=0;
#     for (( i=0; i<${#line}; i++ )); do
#     check=${line:$i:1}
#     if [[ $check =~ [[:space:]] ]]
#     then
#     word=${line:$start:$end}
#         #echo "$word    -   Start is = $start and end is = $end"
#         #echo " "
#             get=0
#          for((j=0 ;j<end;j++ ))   
#             do
#                 char=${word:$j:1}
#                 check=${find:$get:1}
#                 if [[ $check = $char ]]
#                 then get=$(( get+1 ))
#                 elif [[ $check = "." ]]
#                 then get=$(( get+1 ))
#                 fi
#                 if [[ $get -eq $length1 ]]

#                 then  break;
#                 fi

#             done
#                 if [[ $get -eq $length1 ]]
#                     then  echo $word
#                 fi

#         start=$(( start+end+1 ))
#         end=0;
#     else
#     end=$(( end+1 ))
#     fi

#     done

# done < "$input"

################ Q3 #################
# echo -n "Please enter the number of lines to read = "
# read N
# count=1
# file=dummy.txt

# if [ -e dummy.txt ]; then
#   echo -n ""
# else
#   touch dummy.txt
# fi

# echo -n "Even files are : "    
# for FILE in *;do
#       if [[ $FILE != $file ]]
#     then
#        if [ $(( $count % 2 )) -eq 0 ]
#        then
#             echo -n "$FILE "
#             echo `head -$N $FILE` >> dummy.txt
            
#        fi
#        count=$(( count+1 )) 
#     fi
# done
# echo ""
# count=1
# echo -n "Odd files are : "    
# for FILE in *;do
#     if [[ $FILE != $file ]]
#     then
#        if [ $(( $count % 2 )) -eq 1 ]
#        then
#             echo -n "$FILE "
#             echo `tail -$N $FILE` >> dummy.txt
#        fi
#        count=$(( count+1 )) 
#     fi
       
# done

# echo ""
# echo ""

################ Q4 #################
# echo -n "Please enter the file  to check = ";
# read file
# current_date=$(date +%s);
# last_modified=$(stat -c "%Y" $file);
#     if [ $((current - last_modified)) -gt 86400 ]; then
#         echo "File older than 24 hours"
#         touch $file
#         echo -n "New Modified date: "
#         echo `date -r $file`
              
#       else 
#         echo "File is not older than 24 hours"
#     fi


