isPalindrome([]).
isPalindrome([X]).
isPalindrome([X|Y]):- getLastElement(Y,Z), X=Z, removeLastElement(Y,T), isPalindrome(T).

getLastElement([A|B],R):-getLastElement(B,R).
getLastElement([A],A).

removeLastElement([X],[]).
removeLastElement([A|B],T):- removeLastElement(B,Y), T=[A|Y].    

rcd([A,A|C],R):-rcd([A|C],R).
rcd([A],[A]).
rcd([A,B|C],R):-rcd([B|C],T),append([A],T,R).


