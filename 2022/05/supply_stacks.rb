s = [
  ['Z', 'T', 'F', 'R', 'W', 'J', 'G'],
  ['G', 'W', 'M'],
  ['J', 'N', 'H', 'G'],
  ['J', 'R', 'C', 'N', 'W'],
  ['W', 'F', 'S', 'B', 'G', 'Q', 'V', 'M'],
  ['S', 'R', 'T', 'D', 'V', 'W', 'C'],
  ['H', 'B', 'N', 'C', 'D', 'Z', 'G', 'V'],
  ['S', 'J', 'N', 'M', 'G', 'C'],
  ['G', 'P', 'N', 'W', 'C', 'J', 'D', 'L']
]

def move(from, to)
  box = from.pop
  to.push(box)
end

while line = gets do
  inst = line.split(" ")
  moves = inst[1].to_i
  from = inst[3].to_i - 1
  to = inst[5].to_i - 1
  moves.times do
    move(s[from], s[to])
  end
end

res = ""
s.each do |stack|
  res += stack[-1]
end
puts(res)
