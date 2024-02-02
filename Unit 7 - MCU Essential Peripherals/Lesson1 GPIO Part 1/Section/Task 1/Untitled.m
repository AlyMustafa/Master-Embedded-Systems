clear
clc
 data =   [1 1 2 0.01 0.3 0;
           2 2 3 0.02 0.32 0;
           3 1 3 0.03 0.4 0 ;
           4 1 0 0 0.5 0;
           5 2 0 0 0.45 0;
           6 3 0 0 -0.02 0;
           ];
       ybus(3,3) = 0;
       for k= 1:6
           %off diagonal
           if(data(k,2)~=0 && data(k,3)~=0 )
               ybus( data(k,2) , data(k,3) ) = -1/(data(k,4) + 1i*data(k,5));
               ybus( data(k,3) , data(k,2) ) = -1/(data(k,4) + 1i*data(k,5));
               
               %diagonal
               ybus( data(k,2) , data(k,2) ) = ybus( data(k,2) , data(k,2) ) + 1/(data(k,4) + 1i*data(k,5)) + 1i*data(k,6);
               ybus( data(k,3) , data(k,3) ) = ybus( data(k,3) , data(k,3) ) + 1/(data(k,4) + 1i*data(k,5)) + 1i*data(k,6);
           else
               if(data(k,2) ~= 0)
                   bNum = data(k,2);
               else
                   bNum = data(k,3);
               end
                ybus( bNum , bNum ) = ybus( bNum , bNum ) + 1/(data(k,4) + 1i*data(k,5));
           end
       end
        disp(ybus);      
           