% spiral iterator + height check

clear;clc;close all;

terr_dis = 5;
delta_r0 = 10;
r_offset_0 = 5;
radius = delta_r0 + r_offset_0 + 2*terr_dis;

nRings_ = ceil(radius/terr_dis);

nmax_iter = ceil(pi*(radius + 2*terr_dis)^2/terr_dis^2);

pos = 0*[0.2,0.3]*terr_dis;
pos_normalized = pos/terr_dis;
xc = round(pos_normalized(1));
yc = round(pos_normalized(2));

figure('color','w'); hold on; grid on; box on;
plot(pos(1), pos(2), 'bo');

x = 0;
y = 0;
distance_ = 0;
k = 1;
while distance_ < nRings_
    distance_ = distance_ + 1;
    x = distance_;
    y = 0;
    do_check = true;
    while do_check

        pointInMap(1) = x + xc;
        pointInMap(2) = y + yc;
        if (distance_ == nRings_ || distance_ == nRings_ - 1)
            if (norm(pointInMap-pos_normalized)^2<radius^2)

                plot(pointInMap(1)*terr_dis, pointInMap(2)*terr_dis, 'o', 'color', [0.3 0.3 0.3]);
                points(k,:) = [pointInMap(1)*terr_dis, pointInMap(2)*terr_dis]; k = k + 1;
            end
        else
            plot(pointInMap(1)*terr_dis, pointInMap(2)*terr_dis, 'o', 'color', [0.3 0.3 0.3]);
            points(k,:) = [pointInMap(1)*terr_dis, pointInMap(2)*terr_dis]; k = k + 1;
        end

        dx = -((0 < y) - (y < 0));
        dy = ((0 < x) - (x < 0));

        if (dx ~= 0 && int_cast(norm([x + dx, y])) == distance_)
            x = x + dx;
        elseif (dy ~= 0 && int_cast(norm([x, y + dy])) == distance_)
            y = y + dy;
        else
            x = x + dx;
            y = y + dy;
        end
        
        do_check = (x ~= distance_ || y ~= 0);
    end
end

cc = linspace(-pi,pi,361)';
plot(pos(1)+radius*sin(cc), pos(2)+radius*cos(cc), 'r');

plot3(points(:,1), points(:,2), (1:length(points)), '-gs');

function x_int = int_cast(x)

if x<0
    x_int = ceil(x);
else
    x_int = floor(x);
end
end