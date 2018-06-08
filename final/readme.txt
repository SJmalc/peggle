Sean Michalec (me, P1) and Georges Alsankary

This is a recreation of the game called "Peggle", a PopCap game
available on EA Origin. It is a sort of mix between brick breaker
and pachinko, where the object of the game is to clear all orange
pegs, while also clearing blue pegs to score more points. Blue pegs
are worth 10 points, and orange are worth 100. A limitation of this
implementation is that you must not click more than once when you 
shoot the ball otherwise the program will save the following clicks
and use them as shots instead of waiting for more. Another imitation
of our implementation is that the physics for bouncing does not fully
work so we gave the player 5 extra shots, so they have 15 as opposed
to the traditional 10. To quit, the player must hit q.
We chose this game to remake as I have spent very many hours playing 
Peggle, as it is pretty addictive. 
We used the gfx library as well as our own classfor the peg board. 
We controlled the pegs using a 2D vector. Much of the process can 
be seen in the main code. 
Overall it was a pleasure working with Georges, and there is an 
equal ownership of the project between the two of us.

The executable is titled "peggle".