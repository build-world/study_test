rc = 1024;
for ctr = 1:rc
    if ctr <= rc/3
        for cur = 1:rc
            img(ctr, cur) = (cur - 1)/rc;
        end
    elseif ctr >rc/3 && ctr <= rc/3*2
        dx = 2 / rc;
        min = log(dx);
        max = log(2);
        span = max - min;
        for cur = 1:rc
            img(ctr, cur) = (log(dx * cur) - min)/span;
        end
    else
        dx = 2 / rc;
        min = log10(dx);
        max = log10(2);
        span = max - min;
        for cur = 1:rc
            img(ctr, cur) = (log10(dx * cur) - min)/span;
        end
    end
end
imshow(img);
imwrite(im2uint8(img), '.\A1.tif', 'tiff');
