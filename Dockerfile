FROM ubuntu:22.04

RUN apt-get update
RUN apt-get install xinetd -y

ENV TERM xterm

RUN useradd -ms /bin/bash ctfd

WORKDIR /home/crackme1

ADD ./share /home/crackme1

RUN echo "#!/bin/bash" > /home/crackme1/run.sh && \
    echo "/home/crackme1/crackme" >> /home/crackme1/run.sh && \ 
    chmod +x /home/crackme1/run.sh

RUN chown -R 750 /home/crackme1

ADD ./settings/crackme.xinetd /etc/xinetd.d/crackme1

CMD ["/usr/sbin/xinetd", "-dontfork"]
