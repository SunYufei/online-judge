#!/bin/sh

echo "Please choose which LANGUAGE you would use?"
echo "1. c++"
echo "2. java"
echo "3. python"
read -p "Your Choice(1-3): " LANGUAGE_SELECT
echo "Please type name of your file:"
read -p " " FILENAME_SELECT
read -p "Please type ID of the example to test (1-16): " ID_TO_TEST

if [ "$LANGUAGE_SELECT" -eq "1" ]; then
  cp $FILENAME_SELECT ./compile/cpp/source.cpp
  cd ./compile/cpp/
  g++ -I./headers ./objects/event.o ./objects/policy_wrapper.o ./objects/sim.o ./objects/task.o --std=c++17 -DCPP_SOLUTION -DONLINE_JUDGE -DNDEBUG source.cpp -oexe
  rm ./source.cpp
  cd ../..
  mv ./compile/cpp/exe ./runtime/exe
  cd ./runtime
  ./exe configs/sim_config.json traces/trace-$ID_TO_TEST.json
  rm exe
  exit 0

fi

if [ "$LANGUAGE_SELECT" -eq "2" ]; then
  cp $FILENAME_SELECT ./compile/java/source.java
  cd ./compile/java
  javac -cp .:./lib:./lib/gson-2.8.5.jar source.java
  rm ./source.java
  cd ../..
  mv ./compile/java/*.class ./runtime/
  cd ./runtime
  ./runjava configs/sim_config.json traces/trace-$ID_TO_TEST.json
  rm *.class
  exit 0

fi
  
if [ "$LANGUAGE_SELECT" -eq "3" ]; then
  cp $FILENAME_SELECT ./runtime/source.py
  cd ./runtime
  ./runpython configs/sim_config.json traces/trace-$ID_TO_TEST.json
  rm source.py
  exit 0

fi