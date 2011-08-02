require("lunatest")
require("luahapi")

function LogType_test()
	assert_equal(HAPI.DeviceLog.TIME, 0)
end

function LogTypeVectorConstruction_test()
	HAPI.DeviceLog.LogTypeVector{HAPI.DeviceLog.TIME}
end

function DeviceLogConstruction_test()
	HAPI.DeviceLog("dummylog.txt", HAPI.DeviceLog.LogTypeVector{HAPI.DeviceLog.TIME})
end

lunatest.run()
