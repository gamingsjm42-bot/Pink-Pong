START ALGORITHM: InstallAndRunSFML

    SET current_os = GET_SYSTEM_PLATFORM()
    PRINT "Current Operating System: " + current_os

    PRINT "Step 1: Check and Install SFML Dependencies..."
    
    IF current_os EQUALS "Linux" THEN
        EXECUTE_COMMAND("sudo apt-get update")
        EXECUTE_COMMAND("sudo apt-get install -y libsfml-dev")
        
    ELSE IF current_os EQUALS "Windows" THEN
        EXECUTE_COMMAND("vcpkg install sfml")
        
    ELSE
        PRINT "Error: Unsupported Operating System"
        EXIT_PROGRAM
    END IF

    PRINT "Step 2: Configuring and Building Project with CMake..."
    
    IF NOT DIRECTORY_EXISTS("build") THEN
        CREATE_DIRECTORY("build")
    END IF

    IF current_os EQUALS "Windows" THEN
        SET vcpkg_toolchain = "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"
        EXECUTE_COMMAND("cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=" + vcpkg_toolchain)
    ELSE
        EXECUTE_COMMAND("cmake -B build -S .")
    END IF

    EXECUTE_COMMAND("cmake --build build")

    PRINT "Step 3: Launching SFML Application..."
    SET executable_name = "MySFMLApp"

    IF current_os EQUALS "Windows" THEN
        SET run_path = "build/Debug/" + executable_name + ".exe"
    ELSE
        SET run_path = "build/" + executable_name
    END IF

    IF FILE_EXISTS(run_path) THEN
        EXECUTE_COMMAND(run_path)
    ELSE
        PRINT "Error: Executable file not found!"
        EXIT_PROGRAM
    END IF

END ALGORITHM
