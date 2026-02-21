cmake_minimum_required(VERSION 3.8)
project(show_dog)

find_package(ament_cmake REQUIRED)

install(DIRECTORY
  urdf
  meshes
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
