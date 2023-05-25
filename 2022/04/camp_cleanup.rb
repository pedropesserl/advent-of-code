pares_contidos = 0
a = {}
b = {}

while line = gets do
  par = line.split(",")
  a = { menor: par[0].split("-")[0].to_i,
        maior: par[0].split("-")[1].to_i }
  b = { menor: par[1].split("-")[0].to_i,
        maior: par[1].split("-")[1].to_i }
  if (a[:menor] >= b[:menor] and a[:maior] <= b[:maior]) or
     (b[:menor] >= a[:menor] and b[:maior] <= a[:maior]) then
    pares_contidos += 1
  end
end

puts(pares_contidos)
