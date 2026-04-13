float det(float x1, float y1,
          float x2, float y2,
          float x3, float y3)
{
    return (y3 - y1) * (x2 - x1) - (y2 - y1) * (x3 - x1);
}

bool PktWOdcinku(punkt A, punkt B, punkt P)
{
    float w = det(A.x, A.y, B.x, B.y, P.x, P.y);
    
    if (abs(w) > EPS)
        return false;

    return P.x >= min(A.x, B.x) && P.x <= max(A.x, B.x) &&
           P.y >= min(A.y, B.y) && P.y <= max(A.y, B.y);
}