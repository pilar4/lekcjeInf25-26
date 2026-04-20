cw 1
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

cw 3


function Koch(n,x,y,d,alfa){
    var dx=d*cos(alfa);
    var dy=d*sin(alfa);

    if(n==0){
        line(x,y,x+dx,y-dy);
    }
    else{
        Koch(n-1,x,y,d/3,alfa);
        Koch(n-1,x+dx/3,y-dy/3,d/3,alfa+PI/3);
        Koch(n-1,x+dx/2-dy*p3/6,y-dy/2-dx*p3/6,d/3,alfa-PI/3);
        Koch(n-1,x+2*dx/3,y-2*dy/3,d/3,alfa);
    }
}

function setup() {
    createCanvas(600,400);
    p3=sqrt(3);
}

function draw() {
    background(220);
    Koch(4,50,300,500,0);
    noLoop();
}

cw5
function setup() {
  createCanvas(600, 600);
}

function Cantor(n, x, y, d) {
  if (n == 0) {
    line(x, y, x + d, y);
  } else {
    Cantor(n - 1, x, y, d / 3);
    Cantor(n - 1, x + 2 * d / 3, y, d / 3);
  }
}

function DrzewoBinarne(n, x, y, d, alfa) {
  let x1 = x + d * cos(alfa);
  let y1 = y - d * sin(alfa);
  line(x, y, x1, y1);
  if (n > 0) {
    DrzewoBinarne(n - 1, x1, y1, d / 2, alfa + PI / 4);
    DrzewoBinarne(n - 1, x1, y1, d / 2, alfa - PI / 4);
  }
}

function draw() {
  background(220);
  DrzewoBinarne(6, 300, 500, 100, PI / 2);
}
