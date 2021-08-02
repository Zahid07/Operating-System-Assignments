# !/bin/bash
#Name =  Muhammad Zahid
#Roll No =  19i-0469
#Section =  D


rows=$2
choice=$1


if [ $choice = LEFT -o $choice = left ];
then
    for i in `seq $rows`
    do

        for j in `seq $i`
            do
                echo -n  "*"
            done
        echo ""

    done
    rows=$(( rows-1 ))
    for i in `seq $rows`
    do
        j=$(( rows-i ))
        for (( j; j>=0; j-- ))
            do  
                echo -n "*"
            done
        echo ""

    done




elif [ $choice = RIGHT -o $choice = right ]
then 

 space=$(( rows-1 ))
    for i in `seq $rows`
    do
    space=$(( space-1 ))
        for (( j=space;j>=0;j-- ))
            do
                echo -n " "
            done
            
        
        for j in `seq $i`
            do
                echo -n  "*"
            done
        echo ""
    done

    rows=$(( rows-1 ))
    space=$(( space+1 ))
    for i in `seq $rows`
    do

        for (( j=space;j>=0;j-- ))
            do
                echo -n " "
            done
            
        
        j=$(( rows-i ))
        for (( j; j>=0; j-- ))
            do  
                echo -n "*"
            done
    space=$(( space+1 ))
        echo ""
    done

elif [ $choice = FULL -o $choice = full ]
then 

    print=0
    space=$(( rows-1 ))
    for i in `seq $rows`
    do
    space=$(( space-1 ))
        for (( j=0;j<=space;j++ ))
            do
                echo -n  " "
            done
        
        
        for (( j=0;j<=print;j++ ))
            do
                echo -n  "*"
            done
        echo ""
        print=$(( print+2 ))
        
    done
    rows=$(( rows-1 ))
    print=$(( print-3 ))
    space=$(( space+2 ))
    for i in `seq $rows`
    do
        for (( j=space;j>0;j-- ))
            do
                echo -n  " "
            done
        
        
        for (( j=print;j>0;j-- ))
            do
                echo -n  "*"
            done
        echo ""
        print=$(( print-2 ))
        space=$(( space+1 ))
    done


fi
