#!/bin/bash

# define input file path
INFILE="input.txt"

# define cube limits
RED_MAX=12
GREEN_MAX=13
BLUE_MAX=14

# init sum of IDs
sum_ids=0

# save original IFS to restore at end and set IFS to delimiter
OLDIFS="$IFS"

# read the lines of the file into the lines array
mapfile -t lines_arr < "$INFILE"

# 
for line in "${lines_arr[@]}"; do
    #echo line FOR DEBUGGING
    # echo "$line"

    # extract game id
    game_id=$(echo "$line" | grep -oE "Game [0-9]+" | cut -d ' ' -f 2)

    #echo game id FOR DEBUGGING
    # echo "$game_id"

    # tokenize line based on delimiter
    IFS=';' tokens=( $line )

    # reset counts to zero for each game
    red_count=0
    green_count=0
    blue_count=0

    # for each tokenized game
    for token in "${tokens[@]}"; do
        # extract the cube counts from the game description
        temp=$(echo "$token" | grep -oE "\b[0-9]+ red" | cut -d ' ' -f 1)
        if [[ -n "$temp" && "$temp" =~ ^[0-9]+$ && "$temp" -gt "$red_count" ]]; then
            red_count=$temp
        fi

        temp=$(echo "$token" | grep -oE "\b[0-9]+ green" | cut -d ' ' -f 1)
        if [[ -n "$temp" && "$temp" =~ ^[0-9]+$ && "$temp" -gt "$green_count" ]]; then
            green_count=$temp
        fi

        temp=$(echo "$token" | grep -oE "\b[0-9]+ blue" | cut -d ' ' -f 1)
        if [[ -n "$temp" && "$temp" =~ ^[0-9]+$ && "$temp" -gt "$blue_count" ]]; then
            blue_count=$temp
        fi
    done
    
    # if all of the counts are below the maxs, add gameid to sum
    if [ $red_count -le $RED_MAX ] && [ $green_count -le $GREEN_MAX ] && [ $blue_count -le $BLUE_MAX ]; then
        sum_ids=$(($sum_ids + $game_id))
    fi

done

echo "Sum of the IDs of possible games is $sum_ids"