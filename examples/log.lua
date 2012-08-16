require("luahapi")
print("Creating device")
--hd = HAPI.AnyHapticsDevice()
--hd = HAPI.PhantomHapticsDevice()
hd = HAPI.HaptionHapticsDevice("192.168.1.13")
print("Initializing device")
if hd:initDevice() ~= HAPI.HAPIHapticsDevice.SUCCESS then
	print("ERROR: ", hd:getLastErrorMsg())
	os.exit(1)
end

print("Enabling device")
hd:enableDevice()

print("Creating Logger 'effect'")
logger = HAPI.DeviceLog("examplelog.txt", HAPI.DeviceLog.LogTypeVector{HAPI.DeviceLog.TIME, HAPI.DeviceLog.POSITION})

print("Adding effect to device")
hd:addEffect(logger)

print("Transferring objects")
hd:transferObjects()

print("Press enter to stop logging and shut down")
io.stdin:read()

print("Removing effect")
hd:removeEffect(logger)

print("Transferring objects")
hd:transferObjects()

print("Disabling device")
hd:disableDevice()

print("Releasing device")
hd:releaseDevice()

print("done!")
