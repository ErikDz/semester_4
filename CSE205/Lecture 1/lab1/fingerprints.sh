#!/bin/sh

if [ $# -eq 0 ]; then
  echo "Usage: $0 hostname1 [hostname2 hostname3 ...]"
  exit 1
fi

for host in "$@"; do
	# We run the pipeline in a subshell and redirect its output to /dev/null in order to remove the comment.
	fingerprint=$(ssh-keyscan -t ecdsa $host | ssh-keygen  -lf -| awk '{print $2}'| grep -v '^#') > /dev/null 2>&1
  echo "$host $fingerprint"
done
