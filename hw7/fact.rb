def factorial(i)
  if i == 0
    return 1
  else
    return i * factorial(i-1)
  end
end

lst = [ 1 ]
1.upto(5){|n| lst[n]=factorial(n)}
puts lst
