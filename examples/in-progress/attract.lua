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
spring_constant = 100
radius = .01

local num = 0
function attractorFunc(center, spring_constant, radius)
	local myNum = num
	num = num + 1
	print("Creating attractor", myNum, ": a spring attached at", center, "with spring constant", spring_constant, "and radius", radius)
	local spring_effect = HAPI.HapticSpring(center, spring_constant)
	while true do

		while (hd:getPosition() - center).length >= radius do
			coroutine.yield()
		end

		print("Enter attractor", myNum)
		hd:addEffect(spring_effect)
		hd:transferObjects()

		while (hd:getPosition() - center).length < radius do
			coroutine.yield()
		end

		print("Exit attractor", myNum)
		hd:removeEffect(spring_effect)
		hd:transferObjects()
	end
end

attractors = {}
for i=0,0 do
	local currentCenter = center + HAPI.Vec3(0, radius * 2 * i, 0)
	local routine = coroutine.wrap(attractorFunc)
	routine(currentCenter, spring_constant, radius)
	table.insert(attractors, routine)
end

while true do
	for _, v in ipairs(attractors) do
		v()
	end
end
