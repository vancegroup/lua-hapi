require("lunatest")

function test_loads()
	require("luahapi")
	assert_table(HAPI)
	print("HAPI namespace members:")
	for k, v in pairs(HAPI) do
		print("HAPI." .. k)
	end
end

lunatest.run()
