void los(){
    int idol;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            A[i][j] = rand()%2;
        }
    }
    if(rand()%2){
        idol = rand()%N;
        for (int i=0; i<N; i++){
            A[i][idol] = true;
        }
        for (int j=0; j<N; j++){
            A[idol][j] = false;
        }
    }

}

void test(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i!=j) cout<<A[i][j]<<" ";
            else cout<<"   ";
        }
        cout<<endl;
    }
}
