# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    create_array.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiestro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 20:48:41 by abiestro          #+#    #+#              #
#    Updated: 2018/07/30 05:53:10 by abiestro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
shuffle() {
	local i tmp size max rand

	size=${#array[*]}
	max=$(( 32768 / size * size ))

	for ((i=size-1; i>0; i--)); do
		while (( (rand=$RANDOM) >= max )); do :; done
		rand=$(( rand % (i+1) ))
		tmp=${array[i]} array[i]=${array[rand]} array[rand]=$tmp
	done
}

array=( $(for i in {1..500}; do echo $i; done) )
info1=$(echo "\033[1;34mchecker.\033[0m")
info2=$(echo "\033[1;34mpush_swap.\033[0m")
loop() {
	local k;
	for ((k=0; k<50;k++)); do
		shuffle
		echo $info1
		./push_swap  $(printf "%s \n" "${array[@]} ") | ./checker $(printf "%s \n" "${array[@]} ")
		echo $info2
		./push_swap $(printf "%s \n" "${array[@]}") | wc -l
	done
}
loop
