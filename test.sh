counter=0
while [ $counter -le 100 ]
do
	./cub3D maps/haring.cub &
	sleep 0.5
	kill $!
	counter=$(( $counter + 1 ))
done