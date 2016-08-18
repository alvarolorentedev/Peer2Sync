# Deal with updating our repositories.
supervisorctl start redis-server

# Check for the oneshot process to complete.
while ! supervisorctl status redis-server | grep -q 'EXITED'; do sleep 1; done
# Wait for the while loop to break out signalling success.

# Start the late boot process, now that the deployment is complete.
supervisorctl start P2S

# Check for the oneshot process to complete.
while ! supervisorctl status P2S | grep -q 'EXITED'; do sleep 1; done
# And now we should become EXITED to supervisord and any other tasks relying on the above.
