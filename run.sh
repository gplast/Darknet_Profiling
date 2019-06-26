make -j
./darknet detector demo journal/car_ped.data journal/DroNetV3_car_64.cfg journal/DroNetV3_car.weights ../Car_Crossroad.mp4 -dont_show
./darknet detector demo journal/car_ped.data journal/DroNetV3_car_128.cfg journal/DroNetV3_car.weights ../Car_Crossroad.mp4 -dont_show
./darknet detector demo journal/car_ped.data journal/DroNetV3_car_416.cfg journal/DroNetV3_car.weights ../Car_Crossroad.mp4 -dont_show
./darknet detector demo journal/car_ped.data journal/DroNetV3_car_512.cfg journal/DroNetV3_car.weights ../Car_Crossroad.mp4 -dont_show
./darknet detector demo journal/car_ped.data journal/DroNetV3_car_1024.cfg journal/DroNetV3_car.weights ../Car_Crossroad.mp4 -dont_show
./darknet detector demo journal/car_ped.data journal/DroNetV3_car_2048.cfg journal/DroNetV3_car.weights ../Car_Crossroad.mp4 -dont_show