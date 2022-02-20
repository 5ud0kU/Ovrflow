Graph.displayResolution(6,12);

makeTitle = function()
  animation = [];
  animation.push(Graph.animationPart(Graph.Size(" ",18),Math.vector2(1,1)));
  animation.push(Graph.animationPart(Graph.Size("$",18),Math.vector2(1,2)));
  animation.push(Graph.animationPart(Graph.Size("O",18),Math.vector2(1,3)));
  animation.push(Graph.animationPart(Graph.Size("V",18),Math.vector2(1,4)));
  animation.push(Graph.animationPart(Graph.Size("R",18),Math.vector2(1,5)));
  animation.push(Graph.animationPart(Graph.Size("F",18),Math.vector2(1,6)));
  animation.push(Graph.animationPart(Graph.Size("L",18),Math.vector2(1,7)));
  animation.push(Graph.animationPart(Graph.Size("O",18),Math.vector2(1,8)));
  animation.push(Graph.animationPart(Graph.Size("W",18),Math.vector2(1,9)));
  animation.push(Graph.animationPart(Graph.Size("$",18),Math.vector2(1,10)));
  animation.push(Graph.animationPart(Graph.Size(" ",18),Math.vector2(1,11)));
  animation.push(Graph.animationPart(Graph.Size(" ",18),Math.vector2(1,12)));
  Graph.animator(animation);
end function

makeAmem = function()
  //   1 2 3 4 5 6 7 8 9 10 11 12
  //1-[ ][$][O][V][R][F][O][O][D][$][ ][ ]
  //2-[ ][x][x][ ][ ][x][x][ ][ ][x][x][ ]

  makeTitle();

  animation = [];

  for i in range(1,12)
	   animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#918b54"),Math.vector2(2,i)));
	   animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#4a6e47"),Math.vector2(3,i)));
	   if i > 1 and i < 4 or i > 5 and i < 8 or i > 9 and i < 12 then
		   animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#000000"),Math.vector2(4,i)));
		   animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#000000"),Math.vector2(5,i)));
	   else
		   animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#4a6e47"),Math.vector2(4,i)));
		   animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#4a6e47"),Math.vector2(5,i)));
 	   end if
	   animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#4a6e47"),Math.vector2(6,i)));
  end for
  Graph.animator(animation);
end function

overflow = 0;
makeAflo = function()
	if globals.overflow > 0 then
		animation = [];
		for i in range(1,globals.overflow)
      ch = String.stringToList("abcdefghijklmnopqrstuvwxyz0123456789");
      ch.shuffle;
      animation.push(Graph.animationPart(Graph.mark(Graph.Size(ch[0],18),"#7a0c00"),Math.vector2(1,i)));
			animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#7a0c00"),Math.vector2(2,i)));
			animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#7a0c00"),Math.vector2(3,i)));
			animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#7a0c00"),Math.vector2(4,i)));
			animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#7a0c00"),Math.vector2(5,i)));
			animation.push(Graph.animationPart(Graph.mark(Graph.Size("	",20),"#7a0c00"),Math.vector2(6,i)));
		end for
		Graph.animator(animation);
	end if
end function

point = function()
	globals.overflow = globals.overflow + 1;
	if globals.overflow == 12 then exit("you destroyed the server !");
end function

lost = function()
	if globals.overflow > 0 then globals.overflow = globals.overflow - 1;
end function

game = function()
	buffers = ["1","2","3"];

	ch = user_input(str(char(10) + "[1] http [2] ssh [3] ftp [4] leave"+char(10)+"[(B$)]:"));
	if ch == "4" then exit();

	//TODO
	//Here if the client choose to play he have to bet 1BTC

	if typeof(ch.to_int) != "number" then
		makeAmem();
	end if

	buffers.shuffle;
	if buffers[0] == ch then
		point();
		makeAflo();
		user_input("you win " + str(globals.overflow) + " BTC ! press a key for another ?");
		///TODO
		///Here the client win 1btc * overflow
	else
		lost();
		globals.overflow = 0;
		makeAmem();
		user_input("server win! press a key for another ?");
		///TODO
		//Here the client loose is strike and the mem is cleaned
	end if

	game();
end function

makeAmem();
game();
