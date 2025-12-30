NR > 2 {
  Num_of_People++
  Sum_of_Ages += $4
}
END {
  Avg_Age = Sum_of_Ages / Num_of_People
  gsub ( "," , ".", Avg_Age )
  print "Average age: " Avg_Age
}
