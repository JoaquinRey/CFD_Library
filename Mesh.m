classdef Mesh
    %MESH Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        points
        faces
        cells
    end
    
    methods
        function obj = Mesh()
            obj.points = [];
            obj.cells = [];
            for i=0:2
                for j=-1:1
                    for k=-1:1
                        obj.points(end+1,:) = [i,j,k];
                    end
                end
            end
            for i=1:2
                for j=1:2
                    for k=1:2
                        obj.cells(end+1).points = [];
                        obj.cells(end).volume = 0;
                    end
                end
            end
            for i=1:24
                obj.faces(end+1) = [i i+1 i+3 i+4];
                obj.faces(end+1) = [i+1 i+2 i+4 i+5];
            end
        end
        
        function outputArg = method1(obj,inputArg)
            %METHOD1 Summary of this method goes here
            %   Detailed explanation goes here
            outputArg = obj.Property1 + inputArg;
        end
        function [] = makeCube(obj, origin)
            for i=-0.5:0.5
                for j=-0.5:0.5
                    for k=-0.5:0.5
                        obj.points(end+1,:) = [i,j,k]+origin;
                    end
                end
            end

        end
    end
end

