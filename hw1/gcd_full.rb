#! /usr/bin/env ruby

def gcdI(i, j)
    while i!= j
        if i > j
            i = i - j
        else
            j = j - i;
        end
    end
    return i
end

def gcdF(l, j)
  if l > j
    if l%j==0
      return j
    else
      return gcdF(l % j,j)
    end
  else
    if j%l==0
      return l
    else
      return gcdF(l,j%l)
    end
  end
  return l
end


if ARGV.length != 2
  puts "fact.rb usage: [NUMBER]"
  exit
end

puts gcdI(ARGV[0].to_i,ARGV[1].to_i)
puts gcdF(ARGV[0].to_i,ARGV[1].to_i)
