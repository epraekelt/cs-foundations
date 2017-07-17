#!/bin/bash

HR="- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
NC="\033[0m" # No Color
RED="\033[0;31m"
BLUE="\033[0;34m"
PURPLE="\033[0;35m"
GREEN="\033[0;32m"
BOLD="\e[1m"
BOLD_RESET="\e[21m"
SIM_ARGS="-v"

printHelp() {
  printf "${BLUE}${HR}\n| ${BOLD}Foundations Help${BOLD_RESET}\n${HR}${NC}\n"
  printf "${BLUE}|${NC}  Argument Options:\n"
  printf "${BLUE}|${NC}    ${GREEN}-m${NC}    Compile the program (runs 'make')\n"
  printf "${BLUE}|${NC}    ${GREEN}-s${NC}    Compile and run the program\n"
  printf "${BLUE}|${NC}    ${GREEN}-c${NC}    Clean out the program directory (runs 'make clean')\n"
  printf "${BLUE}|${NC}    ${GREEN}-h${NC}    Prints this help message\n"
  printf "${BLUE}${HR}${NC}\n"
}

buildProgram() {
  $(make clean)
  printf "${BLUE}| Building...${NC}\n\n"
  COMPILE=$(make)
}

cleanProgram() {
  printf "${BLUE}| Cleaning up...${NC}\n"
  CLEAN=$(make clean)
}

startProgram() {
  buildProgram
  ./bin/Foundations ${SIM_ARGS}
  echo ""
  cleanProgram
}


if [ $# -ne 0 ]; then
  case "$1" in
    "-m") buildProgram ;;
    "-s") startProgram ;;
    "-c") cleanProgram ;;
    "-h") printHelp ;;
    *) printf "${RED}${BOLD}ERROR: Invalid option${BOLD_RESET}${NC}\n"; printHelp
  esac
else
  printf "${RED}${BOLD}ERROR: No arguments provided${BOLD_RESET}${NC}\n"
  printHelp
fi
