#!/bin/bash

N_present=0
N_missing=0

if [ ! $# == 2 ]; then
  echo Usage: ./checkfiles2.sh [run_from] [run_to]
  exit
fi

for i in $(seq $1 $2) ; do
  filename=run${i}/outdir/particle_lists.oscar
  if [ -e $filename ] ; then
    (( N_present ++ ))
  else
    (( N_missing ++ ))
  fi
done

echo We found: $N_present present and $N_missing missing files.

