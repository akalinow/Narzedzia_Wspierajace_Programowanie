#!/usr/bin/awk -f

$2 == "event" && $4 == "out" {
  NpartDeclared += $5
}
NF == 12 {
  NpartFound ++
}
END {
  print "No. of particles: Declared = " NpartDeclared " , Found = " NpartFound
  if (NpartDeclared == NpartFound) {
    print "All ok."
  } else
    print "Inconsistency!"
}
