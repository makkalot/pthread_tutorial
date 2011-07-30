require 'rake/clean'

pwd = Dir.pwd

PROJECT_NAME = "general"
ERR_SRC = FileList["*.c"]
ERR_OBJ = ERR_SRC.ext('o')
CLEAN.include("*.o")

ERR_EXECUTABLES = ERR_SRC.map do |f|
  f.sub(/\.[^.]+$/, '')
end

ERR_EXECUTABLES.each do |e|
  CLOBBER.include(e)
end

ERR_SRC.each do |src_f|
	obj_f = src_f.sub(/\.[^.]+$/, '')
	obj_f << '.o'	
	
	file obj_f => src_f do |f|
		sh "gcc -g -Wall #{src_f} -c -o #{obj_f}"
	end	
end



ERR_EXECUTABLES.each do |executable|
  file executable => [executable+'.o'] do |t|
	if executable.rindex('pthread')
		sh "gcc -o #{executable} #{executable+'.o'} ../util/err.o -lpthread"
	else
		sh "gcc -o #{executable} #{executable+'.o'} ../util/err.o"
	end
  end
end


desc "Compile #{PROJECT_NAME} Project"
task :compile => ERR_EXECUTABLES do
end

task :prepare do
	Dir.chdir("..")
	sh "rake prepare"
	Dir.chdir(pwd)
end

