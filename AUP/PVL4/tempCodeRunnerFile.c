int resLen = 0;
            for(int i = 0 ; i < dictLen - maxInd + 1; i++){
                int resWortLen = 0;
                if(res[i]=='\0' || res[i]==NULL){
                    break;
                }
                for(int j = 0; j < satzLenOhneLeer; j ++){
                    if(res[i][j]!='\040'){
                        resWortLen++;
                    }
                    

                }
                if(resWortLen == satzLenOhneLeer){
                    resLen++;
                }
            }