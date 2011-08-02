require("lunatest")

function test_loads()
	require("luahapi")
	assert_table(HAPI)
	print("Constructible Types:")
	for k, v in pairs(HAPI) do
		print("HAPI." .. k)
	end
end

lunatest.run()
