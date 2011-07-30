require 'rake/clean'

ERR_SRC = FileList["*.c"]
ERR_OBJ = ERR_SRC.ext('o')
CLEAN.include("*.o")

ERR_EXECUTABLES = ERR_SRC.map do |f|
  f.sub(/\.[^.]+$/, '')
end

ERR_EXECUTABLES.each do |e|
  CLOBBER.include(e)
end


#ERR_EXECUTABLES.each do |executable|
#  file executable => executable+'.o' do |t|
#	sh "touch #{executable}"
#  end
#end


ERR_SRC.each do |src_f|
	obj_f = src_f.sub(/\.[^.]+$/, '')
	obj_f << '.o'	
	
	file obj_f => src_f do |f|
		sh "gcc -g -Wall #{src_f} -c -o #{obj_f}"
	end	
end

task :compile => [ERR_OBJ] do 
end

