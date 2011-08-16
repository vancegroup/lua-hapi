require("luahapi")
hd = HAPI.AnyHapticsDevice()

if hd:initDevice() ~= HAPI.HAPIHapticsDevice.SUCCESS then
	print("ERROR: ", hd:getLastErrorMsg())
end

hd:enableDevice()

print("Press enter to set the attractor location.")
io.stdin:read()

pos = hd:getPosition()
print("Adding an attractor at", pos)


center = hd:getPosition()
xgoal = center.x
radius = .03
spring_constant = 100

scalefactor = 3.1415926 / radius

fx = HAPI.ParsedFunction()
fx:setFunctionString(("sin(%f * (%f - x))"):format(scalefactor, xgoal))
print(fx:getFunction())

fy = HAPI.ParsedFunction()
fy:setFunctionString("0", "y")

fz = HAPI.ParsedFunction()
fz:setFunctionString("0", "z")

effect = HAPI.HapticPositionFunctionEffect(fx, fy, fz)

while true do

	while math.abs(hd:getPosition().x - xgoal) >= radius do
		--print(hd:getPosition().x - xgoal)
	end
	print("Enter")
	hd:addEffect(effect)
	hd:transferObjects()
	
	while math.abs(hd:getPosition().x - xgoal) < radius do
		--print(hd:getPosition().x - xgoal)
	end
	print("Exit")
	hd:removeEffect(effect)
	hd:transferObjects()
end
