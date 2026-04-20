cw 1
function setup() {
  createCanvas(600, 400);
}
function Cantor(n,x,y,d){
  if (n==0){
    line(x,y,x+d,y);
  }
  else{
    Cantor(n-1,x,y,d/3);
    Cantor(n-1,x+2*d/3,y,d/3);
  }
}

function draw() {
  background(220);
  Cantor(3,10,200,580);
  noLoop();
}
cw 2
function setup() {
  createCanvas(600, 400);
}

function Cantor(n,x,y,d){
  if(n==0){
    line(x,y,x+d,y);
  } else {
    Cantor(n-1,x,y,d/3);
    Cantor(n-1,x+2*d/3,y,d/3);
  }
}

function draw() {
  background(220);
  for (n=0;n<7;n++){
    Cantor(n,10,(n+1)*50,580);
  }
}

