# A or X -> rock
# B or Y -> paper
# C or Z -> scissors

def get_play(letter)
  case letter
  when "A", "X"
    return {play: "rock", value: 1}
  when "B", "Y"
    return {play: "paper", value: 2}
  when "C", "Z"
    return {play: "scissors", value: 3}
  else
    return nil
  end
end

def draw(player1, player2)
  return player1 == player2
end

def win(player1, player2)
  if (player1 == "rock" and player2 == "scissors") or
    (player1 == "paper" and player2 == "rock") or
    (player1 == "scissors" and player2 == "paper") then
    return true
  else
    return false
  end
end

score = 0

while line = gets do
  op = get_play(line[0])
  me = get_play(line[2])
  
  if draw(me[:play], op[:play]) then
    score += 3
  else
    if win(me[:play], op[:play]) then
      score += 6
    end
  end

  score += me[:value]
end

puts(score)
