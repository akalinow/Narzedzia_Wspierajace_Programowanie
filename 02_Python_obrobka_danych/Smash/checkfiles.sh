#!/bin/bash

N_present=0
N_missing=0

for i in {1..8} ; do
  filename=run${i}/outdir/particle_lists.oscar
  if [ -e $filename ] ; then
    (( N_present ++ ))
  else
    (( N_missing ++ ))
  fi
done

echo We found: $N_present present and $N_missing missing files.

