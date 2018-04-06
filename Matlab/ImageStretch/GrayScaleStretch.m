rc = 1024;
for ctr = 1:rc
    if ctr <= rc/3
        dx = 2 / (rc - 1);
        min = exp(-1);
        max = exp(1);
        span = max - min;
        for cur = 1:rc
            img(ctr, cur) = (exp(-1 + dx * cur) - min)/span;
        end
    elseif ctr > rc/3 && ctr <= rc/3*2
        for cur = 1:rc
            img(ctr, cur) = (cur - 1)/rc;
        end
    else
        dx = 2 / rc;
        min = log(dx);
        max = log(2);
        span = max - min;
        for cur = 1:rc
            img(ctr, cur) = (log(dx * cur) - min)/span;
        end
    end
end
imshow(img);
imwrite(im2uint8(img), '.\A2.tif', 'tiff');
