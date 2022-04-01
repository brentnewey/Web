FROM nginx
COPY brentnewey.com /usr/share/nginx/brentnewey.com
COPY donnagerardo.com /usr/share/nginx/donnagerardo.com
COPY nginx.conf /etc/nginx/nginx.conf
