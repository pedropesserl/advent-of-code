sum = 0

def priority(item)
  ascii = item.ord
  return ascii - 96 if 97 <= ascii && ascii <= 122
  return ascii - 38 if 65 <= ascii && ascii <= 90
  puts("found invalid character")
  return 0
end

while line = gets do
  found = []
  for i in 0 .. line.length/2-1 do
    found.push(line[i])
  end
  for i in line.length/2 .. line.length-1 do
    if found.include? line[i] then
      sum += priority(line[i])
      break
    end
  end
end

puts(sum)
