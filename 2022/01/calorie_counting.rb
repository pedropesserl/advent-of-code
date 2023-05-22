cal = 0
biggest_cal = 0

while line = gets do
  if line != "\n" then
    cal += line.to_i
  else
    if cal > biggest_cal then
      biggest_cal = cal
    end
    cal = 0
  end
end

puts(biggest_cal)
