pares_contidos = 0


while line = gets do
  
  if (amenor >= bmenor and amaior <= bmaior) or
      (bmenor >= amenor and bmaior <= amaior) then
    pares_contidos += 1
  end
end

puts(pares_contidos)
