bool PrzecOdcinki(punkt A, punkt B, punkt C, punkt D)
{
    float w1, w2, w3, w4;

    w1 = det(A.x, A.y, B.x, B.y, C.x, C.y);
    w2 = det(A.x, A.y, B.x, B.y, D.x, D.y);
    w3 = det(C.x, C.y, D.x, D.y, A.x, A.y);
    w4 = det(C.x, C.y, D.x, D.y, B.x, B.y);

    if (w1 * w2 < 0 && w3 * w4 < 0) return true;

    if (PktWodcinku(A, B, C)) return true;
    if (PktWodcinku(A, B, D)) return true;
    if (PktWodcinku(C, D, A)) return true;
    if (PktWodcinku(C, D, B)) return true;

    return false;
}