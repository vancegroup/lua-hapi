require("luahapi")
function pause()
	print("press enter to continue...")
	io.stdin:read()
	print("")
end

print("Creating device")
--hd = HAPI.AnyHapticsDevice()
--hd = HAPI.PhantomHapticsDevice()
hd = HAPI.HaptionHapticsDevice("192.168.1.13")
pause()

print("Initializing device")
if hd:initDevice() ~= HAPI.HAPIHapticsDevice.SUCCESS then
	print("ERROR: ", hd:getLastErrorMsg())
	pause()
	os.exit(1)
end
pause()

print("Enabling device")
hd:enableDevice()
pause()

print("Device is currently at", hd:getPosition())

--center = HAPI.Vec3(0.206835, 0.500593,0.338449)
center = hd:getPosition()
spring_constant = 100

print("Creating effect: a spring attached at ", center, " with spring constant ", spring_constant)
spring_effect = HAPI.HapticSpring(center, spring_constant)
pause()

print("Adding effect to device")
hd:addEffect(spring_effect)
pause()

print("Transfering objects")
hd:transferObjects()
pause()

print("will remove effect...")
pause()

print("Removing effect")
hd:removeEffect(spring_effect)
pause()

print("Transfering objects")
hd:transferObjects()
pause()

print("Disabling device")
hd:disableDevice()
pause()

print("Releasing device")
hd:releaseDevice()
pause()

print("done!")
