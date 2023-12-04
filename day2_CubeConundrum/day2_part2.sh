#!/bin/bash

# define input file path
INFILE="input.txt"

# init sum of IDs
sum_powers=0

# read the lines of the file into the lines array
mapfile -t lines_arr < "$INFILE"

# for each line now in lines array
for line in "${lines_arr[@]}"; do
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
        if [[ "$temp" -gt "$red_count" ]]; then
            red_count=$temp
        fi

        temp=$(echo "$token" | grep -oE "\b[0-9]+ green" | cut -d ' ' -f 1)
        if [[ "$temp" -gt "$green_count" ]]; then
            green_count=$temp
        fi

        temp=$(echo "$token" | grep -oE "\b[0-9]+ blue" | cut -d ' ' -f 1)
        if [[ "$temp" -gt "$blue_count" ]]; then
            blue_count=$temp
        fi
    done
    
    # find the power of the set of cubes
    power=$(($red_count * $green_count * $blue_count))

    # add the power to the sum of powers
    sum_powers=$(($sum_powers + $power))

done

echo "Sum of the powers of every game is $sum_powers"